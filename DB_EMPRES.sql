-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: db_empres
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `maarcas`
--

DROP TABLE IF EXISTS `maarcas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `maarcas` (
  `idmaarcas` smallint NOT NULL,
  `marcaa` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idmaarcas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `maarcas`
--

LOCK TABLES `maarcas` WRITE;
/*!40000 ALTER TABLE `maarcas` DISABLE KEYS */;
/*!40000 ALTER TABLE `maarcas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productoos`
--

DROP TABLE IF EXISTS `productoos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `productoos` (
  `idproductoos` int NOT NULL,
  `productoo` varchar(45) DEFAULT NULL,
  `id_maarcas` smallint DEFAULT NULL,
  `Descripcion` varchar(100) DEFAULT NULL,
  `precioo_cossto` decimal(8,2) DEFAULT NULL,
  `precioo_ventaa` decimal(8,2) DEFAULT NULL,
  `existenciaa` int DEFAULT NULL,
  `fecha_ingresoo` datetime DEFAULT NULL,
  PRIMARY KEY (`idproductoos`),
  KEY `maarcas_id_maarcas_productoos_idx` (`id_maarcas`),
  CONSTRAINT `maarcas_id_maarcas_productoos` FOREIGN KEY (`id_maarcas`) REFERENCES `maarcas` (`idmaarcas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productoos`
--

LOCK TABLES `productoos` WRITE;
/*!40000 ALTER TABLE `productoos` DISABLE KEYS */;
/*!40000 ALTER TABLE `productoos` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-12 23:36:55
