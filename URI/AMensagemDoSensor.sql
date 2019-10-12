CREATE TABLE records (id INT, temperature INT, mark INT, PRIMARY KEY(id));

INSERT INTO records VALUES (1, 30, 1);
INSERT INTO records VALUES (2, 30, 1);
INSERT INTO records VALUES (3, 30, 1);
INSERT INTO records VALUES (4, 32, 2);
INSERT INTO records VALUES (5, 32, 2);
INSERT INTO records VALUES (6, 32, 2);
INSERT INTO records VALUES (7, 32, 2);
INSERT INTO records VALUES (8, 30, 3);
INSERT INTO records VALUES (9, 30, 3);
INSERT INTO records VALUES (10, 30, 3);
INSERT INTO records VALUES (11, 31, 4);
INSERT INTO records VALUES (12, 31, 4);
INSERT INTO records VALUES (13, 33, 5);
INSERT INTO records VALUES (14, 33, 5);
INSERT INTO records VALUES (15, 33, 5);

SELECT
records.temperature,
(SELECT COUNT(*) FROM records rec2 WHERE rec2.temperature = records.temperature  AND rec2.mark = records.mark) AS number_of_records
FROM records GROUP BY temperature, mark ORDER BY mark;
