CREATE TABLE empregados (cpf VARCHAR(15), enome VARCHAR(60), salario FLOAT, cpf_supervisor VARCHAR(15), dnumero INT, PRIMARY KEY(cpf));

INSERT INTO empregados VALUES('49382234322', 'Joao Silva',     2350, '2434332222', 1010);
INSERT INTO empregados VALUES('586733922290', 'Mario Silveira', 3500, '2434332222', 1010);
INSERT INTO empregados VALUES('2434332222'  , 'Aline Barros',   2350, null, 1010);
INSERT INTO empregados VALUES('1733332162'  , 'Tulio Vidal',   8350, null, 1020);
INSERT INTO empregados VALUES('4244435272'  , 'Juliana Rodrigues',   3310, null, 1020);
INSERT INTO empregados VALUES('1014332672'  , 'Natalia Marques',   2900, null, 1010);

CREATE TABLE departamentos (dnumero INT, dnome VARCHAR(60), cpf_gerente VARCHAR(15), PRIMARY KEY (dnumero));

INSERT INTO departamentos VALUES(1010, 'Pesquisa', '49382234322');
INSERT INTO departamentos VALUES(1020, 'Ensino', '2434332222');

CREATE TABLE trabalha (cpf_emp VARCHAR(15), pnumero INT);

INSERT INTO trabalha VALUES ('49382234322', 2010);
INSERT INTO trabalha VALUES ('586733922290', 2020);
INSERT INTO trabalha VALUES ('49382234322', 2020);

CREATE TABLE projetos (pnumero INT, pnome VARCHAR(45), dnumero INT, PRIMARY KEY(pnumero));

INSERT INTO projetos VALUES (2010, 'Alpha', 1010);
INSERT INTO projetos VALUES (2020, 'Beta', 1020);

SELECT
empregados.cpf,
empregados.enome,
departamentos.dnome
FROM empregados JOIN departamentos ON empregados.dnumero = departamentos.dnumero
WHERE (SELECT COUNT(*) FROM trabalha WHERE trabalha.cpf_emp = empregados.cpf) = 0 ORDER BY empregados.cpf;
