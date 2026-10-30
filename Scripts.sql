-- 1 ELIMINAMOS LA TABLA POR SI YA EXISTIERA
DROP TABLE Usuario;

-- 2. CREAMOS LA TABLA
CREATE TABLE Usuario(
	idUsuario int PRIMARY KEY IDENTITY(1,1) NOT NULL,
	nombres varchar(50) NOT NULL,
	apellidos varchar(50) NOT NULL,
	correo varchar(50) NOT NULL,
	usuario varchar(12) NOT NULL,
	contrasenia varchar(25) NOT NULL,
	estado char(1) NOT NULL DEFAULT ('A')
);

-- 3. Aquí van todos tus INSERT generados
INSERT Usuario (nombres, apellidos, correo, usuario, contrasenia, estado) 
VALUES ('Manuel', 'Chávez', 'mhchavez@pucp.pe', 'admin', 'admin', 'A');
-- ... resto de inserts

DROP TABLE Estacion;

CREATE TABLE Estacion (
EstacionId INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
Alias NVARCHAR(100),
Ubicacion NVARCHAR(100),
Estado INT,
CapacidadKgH FLOAT,
HorasOperacion FLOAT
);
-- Insertar estaciones clasificadoras de ejemplo
INSERT INTO Estacion VALUES ('Separador Magnético A', 'Zona de Extracción de Metales', 1, 480.0, 1250.5);
INSERT INTO Estacion VALUES ('Brazo Neumático B', 'Línea de Clasificación 2', 2, 320.0, 850.0);
INSERT INTO Estacion VALUES ('Estación Óptica C', 'Zona de Compactación', 1, 610.0, 3100.2);


DROP TABLE EstadoOperativo;

CREATE TABLE EstadoOperativo (
idEstadoOperativo INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
descripcion NVARCHAR(100)
);
-- Insertar estaciones clasificadoras de ejemplo
INSERT INTO EstadoOperativo VALUES ('Operativo');
INSERT INTO EstadoOperativo VALUES ('En Mantenimiento');
INSERT INTO EstadoOperativo VALUES ('Falla Crítica');
INSERT INTO EstadoOperativo VALUES ('Apagado');