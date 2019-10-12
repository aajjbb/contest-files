CREATE TABLE products (id INT, name VARCHAR(30), type CHAR, price NUMERIC, PRIMARY KEY(id));

INSERT INTO products VALUES (1, 'Monitor', 'B', 0);
INSERT INTO products VALUES (2, 'Headset', 'A', 0);
INSERT INTO products VALUES (3, 'PC Case', 'A', 0);
INSERT INTO products VALUES (4, 'Computer Desk', 'C', 0);
INSERT INTO products VALUES (5, 'Gaming Chair', 'C', 0);
INSERT INTO products VALUES (6, 'Mouse', 'A', 0);

SELECT
products.name,
CASE
WHEN type = 'A' THEN 20.0
WHEN type = 'B' THEN 70.0
ELSE  530.5
END AS price
FROM products
ORDER BY type ASC, id DESC;
