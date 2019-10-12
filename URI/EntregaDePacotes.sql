CREATE TABLE users (id INT, name VARCHAR(30), address VARCHAR(50), PRIMARY KEY(id));
CREATE TABLE packages (id_package INT, id_user_sender INT, id_user_receiver INT, color VARCHAR(50), year INT, PRIMARY KEY(id_package));

INSERT INTO users VALUES (1, 'Edgar Codd', 'England');
INSERT INTO users VALUES (2, 'Peter Chen', 'Taiwan');
INSERT INTO users VALUES (3, 'Jim Grey', 'US');
INSERT INTO users VALUES (4, 'Elizabeth ONeil', 'US');

INSERT INTO packages VALUES(1, 1, 2, 'blue', 2015);
INSERT INTO packages VALUES(2, 1, 3, 'blue', 2019);
INSERT INTO packages VALUES(3, 2, 4, 'red', 2019);
INSERT INTO packages VALUES(4, 2, 1, 'green', 2018);
INSERT INTO packages VALUES(5, 3, 4, 'red', 2015);
INSERT INTO packages VALUES(6, 4, 3, 'blue', 2019);

SELECT
packages.year,
senders.name,
receivers.name
FROM packages
LEFT JOIN users senders   ON senders.id   = packages.id_user_sender   AND senders.address   != 'Taiwan'
LEFT JOIN users receivers ON receivers.id = packages.id_user_receiver AND receivers.address != 'Taiwan'
WHERE
senders.address   != 'Taiwan'
AND receivers.address != 'Taiwan'
AND (packages.year = 2015
OR  packages.color = 'blue')
ORDER BY packages.year DESC;
