CREATE TABLE value_table (amount INT);

INSERT INTO value_table VALUES (4);
INSERT INTO value_table VALUES (6);
INSERT INTO value_table VALUES (7);
INSERT INTO value_table VALUES (1);
INSERT INTO value_table VALUES (1);
INSERT INTO value_table VALUES (2);
INSERT INTO value_table VALUES (3);
INSERT INTO value_table VALUES (2);
INSERT INTO value_table VALUES (3);
INSERT INTO value_table VALUES (1);
INSERT INTO value_table VALUES (5);
INSERT INTO value_table VALUES (6);
INSERT INTO value_table VALUES (1);
INSERT INTO value_table VALUES (7);
INSERT INTO value_table VALUES (8);
INSERT INTO value_table VALUES (9);
INSERT INTO value_table VALUES (10);
INSERT INTO value_table VALUES (11);
INSERT INTO value_table VALUES (12);
INSERT INTO value_table VALUES (4);
INSERT INTO value_table VALUES (5);
INSERT INTO value_table VALUES (5);
INSERT INTO value_table VALUES (3);
INSERT INTO value_table VALUES (6);
INSERT INTO value_table VALUES (2);
INSERT INTO value_table VALUES (2);
INSERT INTO value_table VALUES (1);


WITH counter AS (
SELECT amount,
(SELECT COUNT(*) FROM value_table helper WHERE value_table.amount = helper.amount) AS counter
FROM value_table GROUP BY amount ORDER BY counter DESC)
