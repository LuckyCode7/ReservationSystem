-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: gabinet
-- ------------------------------------------------------
-- Server version	5.7.21-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `godziny`
--

DROP TABLE IF EXISTS `godziny`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `godziny` (
  `godziny_id` int(11) NOT NULL AUTO_INCREMENT,
  `uzytkownik_id` int(11) NOT NULL,
  `pon_od` time DEFAULT NULL,
  `pon_do` time DEFAULT NULL,
  `wt_od` time DEFAULT NULL,
  `wt_do` time DEFAULT NULL,
  `śr_od` time DEFAULT NULL,
  `śr_do` time DEFAULT NULL,
  `czw_od` time DEFAULT NULL,
  `czw_do` time DEFAULT NULL,
  `pt_od` time DEFAULT NULL,
  `pt_do` time DEFAULT NULL,
  `sob_od` time DEFAULT NULL,
  `sob_do` time DEFAULT NULL,
  PRIMARY KEY (`godziny_id`),
  UNIQUE KEY `godziny_id_UNIQUE` (`godziny_id`),
  KEY `fk_godziny_uzytkownik_idx` (`uzytkownik_id`),
  CONSTRAINT `fk_godziny_uzytkownik` FOREIGN KEY (`uzytkownik_id`) REFERENCES `uzytkownik` (`uzytkownik_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `godziny`
--

LOCK TABLES `godziny` WRITE;
/*!40000 ALTER TABLE `godziny` DISABLE KEYS */;
INSERT INTO `godziny` VALUES (6,1,'09:00:00','18:00:00','09:00:00','13:00:00','07:00:00','11:00:00','09:00:00','15:00:00','09:00:00','16:00:00','09:00:00','16:00:00');
/*!40000 ALTER TABLE `godziny` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-07-16 11:28:46
