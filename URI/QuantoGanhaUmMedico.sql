CREATE TABLE doctors (id INT, name VARCHAR(50), PRIMARY KEY(id));

INSERT INTO doctors VALUES(1, 'Arlino');
INSERT INTO doctors VALUES(2, 'Tiago');
INSERT INTO doctors VALUES(3, 'Amanda');
INSERT INTO doctors VALUES(4, 'Wellington');

CREATE TABLE work_shifts (id INT, name VARCHAR(50), bonus NUMERIC, PRIMARY KEY(id));

INSERT INTO work_shifts VALUES(1, 'nocturnal', 15);
INSERT INTO work_shifts VALUES(2, 'afternoon', 2);
INSERT INTO work_shifts VALUES(3, 'day', 1);

CREATE TABLE attendances (id INT, id_doctor INT, hours INT, id_work_shift INT, PRIMARY KEY(id));

INSERT INTO attendances VALUES(1, 1, 5, 1);
INSERT INTO attendances VALUES(2, 3, 2, 1);
INSERT INTO attendances VALUES(3, 3, 3, 2);
INSERT INTO attendances VALUES(4, 2, 2, 3);
INSERT INTO attendances VALUES(5, 1, 5, 3);
INSERT INTO attendances VALUES(6, 4, 1, 3);
INSERT INTO attendances VALUES(7, 4, 2, 1);
INSERT INTO attendances VALUES(8, 3, 2, 2);
INSERT INTO attendances VALUES(9, 2, 4, 2);

WITH salarios AS (
SELECT
id_doctor,
(SELECT
SUM(helper_at.hours * 150 + helper_at.hours * 150 * work_shifts.bonus / 100.0)
FROM attendances helper_at JOIN work_shifts ON work_shifts.id = helper_at.id_work_shift AND attendances.id_doctor = helper_at.id_doctor)
AS salario
FROM attendances GROUP BY id_doctor
)

SELECT doctors.name, ROUND(salarios.salario, 1) FROM doctors JOIN salarios ON doctors.id = salarios.id_doctor ORDER BY salarios.salario DESC;
