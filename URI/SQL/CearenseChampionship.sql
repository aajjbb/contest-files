WITH matches_results AS 
(
  SELECT
    teams.id,
    teams.name,
    COUNT(*) AS matches_count,
    (
      SELECT
        COUNT(*) 
      FROM
        matches AS matches_wins 
      WHERE
        (
          matches_wins.team_1_goals > matches_wins.team_2_goals 
          AND matches_wins.team_1 = teams.id 
        )
        OR 
        (
          matches_wins.team_1_goals < matches_wins.team_2_goals 
          AND matches_wins.team_2 = teams.id 
        )
    )
    AS victories,
    (
      SELECT
        COUNT(*) 
      FROM
        matches AS matches_defeats 
      WHERE
        (
          matches_defeats.team_1_goals < matches_defeats.team_2_goals 
          AND matches_defeats.team_1 = teams.id 
        )
        OR 
        (
          matches_defeats.team_1_goals > matches_defeats.team_2_goals 
          AND matches_defeats.team_2 = teams.id 
        )
    )
    AS defeats,
    (
      SELECT
        COUNT(*) 
      FROM
        matches AS matches_draws 
      WHERE
        matches_draws.team_1_goals = matches_draws.team_2_goals 
        AND 
        (
          matches_draws.team_1 = teams.id 
          OR matches_draws.team_2 = teams.id
        )
    )
    AS draws 
  FROM
    teams 
    JOIN
      matches 
      ON teams.id = matches.team_1 
      OR teams.id = matches.team_2 
  GROUP BY
    1 
)
SELECT
  name,
  matches_count AS matches,
  victories,
  defeats,
  draws,
  SUM(3 * victories + draws) AS score 
FROM
  matches_results 
GROUP BY
  1,
  2,
  3,
  4,
  5 
ORDER BY
  score DESC,
  victories DESC,
  draws DESC,
  defeats ASC,
  name ASC;
