-- MySQL dump 10.13  Distrib 8.0.39, for Linux (x86_64)
--
-- Host: localhost    Database: databaseRecommendationEngine
-- ------------------------------------------------------
-- Server version	8.0.39-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Feedback`
--

DROP TABLE IF EXISTS `Feedback`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Feedback` (
  `feedbackId` bigint unsigned NOT NULL AUTO_INCREMENT,
  `userId` bigint unsigned NOT NULL,
  `MenuItemId` bigint unsigned NOT NULL,
  `Rating` int NOT NULL,
  `comment` varchar(255) NOT NULL,
  `timestamp` date NOT NULL,
  PRIMARY KEY (`feedbackId`),
  KEY `userId` (`userId`),
  KEY `Feedback_ibfk_2` (`MenuItemId`),
  CONSTRAINT `Feedback_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`),
  CONSTRAINT `Feedback_ibfk_2` FOREIGN KEY (`MenuItemId`) REFERENCES `MenuItem` (`menuItemId`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=92 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Feedback`
--

LOCK TABLES `Feedback` WRITE;
/*!40000 ALTER TABLE `Feedback` DISABLE KEYS */;
INSERT INTO `Feedback` VALUES (1,1,1,5,'Delicious and perfect!','2024-06-01'),(2,2,3,4,'Very tasty, but a bit too spicy.','2024-06-02'),(3,3,5,3,'It was okay, nothing special.','2024-06-03'),(4,4,2,5,'Absolutely loved it!','2024-06-04'),(5,5,4,4,'Good but could use more seasoning.','2024-06-05'),(6,6,6,5,'Amazing dish, highly recommend!','2024-06-06'),(7,7,8,4,'Pretty good, will order again.','2024-06-07'),(8,8,7,5,'Fantastic flavor, well cooked.','2024-06-08'),(9,9,9,3,'Average, expected more.','2024-06-09'),(10,10,10,5,'Perfectly sweet and delightful!','2024-06-10'),(11,1,11,4,'Eggs were cooked perfectly, but could use more seasoning.','2024-06-11'),(12,2,12,5,'Pancakes were fluffy and delicious, loved the syrup!','2024-06-12'),(13,3,13,3,'Pulao was okay, needed more vegetables.','2024-06-13'),(14,4,14,4,'Delicious chicken curry, just the right amount of spice.','2024-06-14'),(15,5,15,4,'Tacos were good, fish was fresh.','2024-06-15'),(16,6,16,5,'Perfectly cooked steak, very tender.','2024-06-16'),(17,7,17,3,'Vegetable biryani was decent, could be more flavorful.','2024-06-17'),(18,8,18,5,'Chocolate cake was heavenly, loved it!','2024-06-18'),(19,9,19,4,'Spicy chicken wings were tasty, great appetizer.','2024-06-19'),(20,10,20,5,'Refreshing fruit salad, perfect for breakfast.','2024-06-20'),(21,1,13,4,'Pulao was delicious, loved the mix of spices.','2024-06-21'),(22,2,14,5,'Chicken curry was outstanding, a must-try!','2024-06-22'),(23,3,15,3,'Tacos were okay, expected more flavor.','2024-06-23'),(24,4,16,4,'Steak was excellent, perfectly grilled.','2024-06-24'),(25,5,17,4,'Vegetable biryani was tasty, good portion size.','2024-06-25'),(26,6,18,5,'Chocolate cake was divine, rich and moist.','2024-06-26'),(27,7,19,3,'Spicy chicken wings were too spicy for my taste.','2024-06-27'),(28,8,20,4,'Fresh fruit salad, loved the assortment of fruits.','2024-06-28'),(29,9,11,3,'Egg Benedict was alright, not very flavorful.','2024-06-29'),(30,10,12,5,'Best pancakes ever, fluffy and delicious!','2024-06-30'),(31,1,11,5,'Egg Benedict was amazing, loved the hollandaise sauce!','2024-07-01'),(32,2,12,4,'Pancakes were good, could be a bit crispier.','2024-07-02'),(33,3,13,3,'Pulao lacked seasoning, needs improvement.','2024-07-03'),(34,4,14,3,'Chicken curry was flavorful, but a bit too spicy.','2024-07-04'),(35,5,15,5,'Fish Tacos were superb, fresh and tasty.','2024-07-05'),(36,6,16,4,'Steak was good, could have been more tender.','2024-07-06'),(37,7,17,3,'Vegetable biryani was okay, could use more vegetables.','2024-07-07'),(38,8,18,5,'Chocolate cake was heavenly, loved every bite!','2024-07-08'),(39,9,19,4,'Spicy chicken wings were delicious, perfect level of spice.','2024-07-09'),(40,10,20,5,'Refreshing fruit salad, perfect for a summer day.','2024-07-10'),(41,1,1,1,'Masala Dosa was cold and lacked flavor.','2024-07-11'),(42,2,1,5,'Masala Dosa was fantastic, crispy and flavorful.','2024-07-12'),(43,3,2,1,'Aloo Paratha was too oily and bland.','2024-07-13'),(44,4,2,5,'Aloo Paratha was perfect, loved it!','2024-07-14'),(45,5,3,2,'Paneer Butter Masala was okay, but not great.','2024-07-15'),(46,6,3,4,'Paneer Butter Masala was delicious, creamy and rich.','2024-07-16'),(47,7,4,1,'Chole Bhature was awful, too salty.','2024-07-17'),(48,8,4,5,'Chole Bhature was amazing, just like home.','2024-07-18'),(49,9,5,3,'Chicken Biryani was average, expected more.','2024-07-19'),(50,10,5,4,'Chicken Biryani was good, nice spices.','2024-07-20'),(51,1,6,1,'Rogan Josh was too spicy and overcooked.','2024-07-21'),(52,2,6,5,'Rogan Josh was tender and perfectly spiced.','2024-07-22'),(53,3,7,2,'Butter Chicken was too sweet.','2024-07-23'),(54,4,7,4,'Butter Chicken was creamy and flavorful.','2024-07-24'),(55,5,8,3,'Palak Paneer was bland, needed more spices.','2024-07-25'),(56,6,8,4,'Palak Paneer was delicious, very flavorful.','2024-07-26'),(57,7,9,1,'Idli Sambar was dry and tasteless.','2024-07-27'),(58,8,9,5,'Idli Sambar was soft and delicious.','2024-07-28'),(59,9,10,2,'Lamb Vindaloo was too tough.','2024-07-29'),(60,1,10,5,'Lamb Vindaloo was tender and spicy.','2024-07-30'),(61,1,11,1,'Egg Benedict was undercooked.','2024-07-31'),(62,2,11,5,'Egg Benedict was perfect, loved the sauce.','2024-08-01'),(63,3,12,2,'Pancakes were too thick and dry.','2024-08-02'),(64,4,12,5,'Pancakes were fluffy and delicious.','2024-08-03'),(65,5,13,1,'Pulao lacked flavor and was undercooked.','2024-08-04'),(66,6,13,4,'Pulao was well-cooked and tasty.','2024-08-05'),(67,7,14,1,'Chicken Curry was too oily.','2024-08-06'),(68,8,14,5,'Chicken Curry was rich and flavorful.','2024-08-07'),(69,9,15,3,'Fish Tacos were okay, not very fresh.','2024-08-08'),(70,10,15,4,'Fish Tacos were fresh and tasty.','2024-08-09'),(71,1,16,1,'Steak was tough and overcooked.','2024-08-10'),(72,2,16,5,'Steak was tender and juicy.','2024-08-11'),(73,3,17,2,'Vegetable Biryani was bland.','2024-08-12'),(74,4,17,4,'Vegetable Biryani was flavorful and well-cooked.','2024-08-13'),(75,5,18,3,'Chocolate Cake was too sweet.','2024-08-14'),(76,6,18,5,'Chocolate Cake was rich and moist.','2024-08-15'),(77,9,20,3,'Fruit Salad was okay, not very fresh.','2024-08-18'),(78,10,20,4,'Fruit Salad was fresh and refreshing.','2024-08-19'),(81,1,21,1,'The curry was too watery and bland.','2024-07-04'),(82,2,21,1,'Vegetables were not cooked properly.','2024-07-04'),(83,3,22,1,'The fish was overcooked and dry.','2024-07-04'),(84,4,22,1,'Too salty and greasy.','2024-07-04'),(85,5,23,1,'Mushroom soup was too watery and tasteless.','2024-07-04'),(86,6,23,1,'No flavor and too much cream.','2024-07-04'),(91,2,19,3,'good','2024-07-04');
/*!40000 ALTER TABLE `Feedback` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MenuItem`
--

DROP TABLE IF EXISTS `MenuItem`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `MenuItem` (
  `menuItemId` bigint unsigned NOT NULL AUTO_INCREMENT,
  `menuItemName` varchar(255) NOT NULL,
  `menuItemType` int NOT NULL,
  `Availability` tinyint(1) NOT NULL,
  `Price` decimal(10,2) NOT NULL,
  `vegetarianPreference` int DEFAULT NULL,
  `spiceLevelOption` int DEFAULT NULL,
  `foodPreference` int DEFAULT NULL,
  `sweetToothPreference` int DEFAULT NULL,
  PRIMARY KEY (`menuItemId`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MenuItem`
--

LOCK TABLES `MenuItem` WRITE;
/*!40000 ALTER TABLE `MenuItem` DISABLE KEYS */;
INSERT INTO `MenuItem` VALUES (1,'Masala Dosa',1,1,6.99,1,3,2,0),(2,'Aloo Paratha',1,1,5.49,1,2,1,0),(3,'Paneer Butter Masala',2,1,8.99,1,2,1,0),(4,'Chole Bhature',2,1,7.49,1,2,1,0),(5,'Chicken Biryani',2,1,10.99,2,3,1,0),(6,'Rogan Josh',3,1,12.99,2,3,1,0),(7,'Butter Chicken',3,1,11.49,2,2,1,0),(8,'Palak Paneer',3,1,9.99,1,2,1,0),(9,'Idli Sambar',1,1,4.99,1,2,2,0),(10,'Lamb Vindaloo',3,1,13.99,2,3,1,0),(11,'Egg Benedict',1,1,7.99,3,1,3,0),(12,'Pancakes',1,1,5.99,1,1,3,1),(13,'Pulao',2,1,8.49,1,2,1,0),(14,'Chicken Curry',2,1,9.99,2,3,1,0),(15,'Fish Tacos',2,1,10.49,2,2,3,0),(16,'Steak',3,1,15.99,2,3,3,0),(17,'Vegetable Biryani',2,1,9.49,1,3,1,0),(18,'Chocolate Cake',3,1,6.99,1,1,3,1),(19,'Spicy Chicken Wings',3,1,11.49,2,3,3,0),(20,'Fruit Salad',1,1,4.99,1,1,3,1),(21,'Mixed Vegetable Curry',2,1,130.00,1,2,1,0),(22,'Fish Fry',2,1,180.00,2,1,2,0),(23,'Mushroom Soup',3,1,100.00,1,3,3,0),(26,'Apple Pie',1,1,80.00,1,3,3,1),(27,'Blueberry Cheese cake',3,1,120.00,3,3,3,1);
/*!40000 ALTER TABLE `MenuItem` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `NextDayMenuVoting`
--

DROP TABLE IF EXISTS `NextDayMenuVoting`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `NextDayMenuVoting` (
  `menuItemId` bigint unsigned NOT NULL,
  `voteCount` bigint NOT NULL DEFAULT '0',
  `rating` double DEFAULT NULL,
  `sentiments` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`menuItemId`),
  CONSTRAINT `NextDayMenuVoting_ibfk_1` FOREIGN KEY (`menuItemId`) REFERENCES `MenuItem` (`menuItemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `NextDayMenuVoting`
--

LOCK TABLES `NextDayMenuVoting` WRITE;
/*!40000 ALTER TABLE `NextDayMenuVoting` DISABLE KEYS */;
INSERT INTO `NextDayMenuVoting` VALUES (1,0,3.6666666666666665,'crispy, lacked, cold, delicious'),(11,0,3.6,'loved, not very, more'),(14,0,3.6,'too, rich, delicious'),(17,0,3.2,'more, flavorful, good'),(18,0,4.6,'rich, loved, too'),(19,0,3.5,'good, perfect, too, great');
/*!40000 ALTER TABLE `NextDayMenuVoting` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Notification`
--

DROP TABLE IF EXISTS `Notification`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Notification` (
  `notificationId` int NOT NULL AUTO_INCREMENT,
  `notificationTitle` varchar(255) NOT NULL,
  `message` text NOT NULL,
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`notificationId`)
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Notification`
--

LOCK TABLES `Notification` WRITE;
/*!40000 ALTER TABLE `Notification` DISABLE KEYS */;
/*!40000 ALTER TABLE `Notification` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `User`
--

DROP TABLE IF EXISTS `User`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `User` (
  `userId` bigint unsigned NOT NULL AUTO_INCREMENT,
  `userName` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `Role` int NOT NULL,
  PRIMARY KEY (`userId`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `User`
--

LOCK TABLES `User` WRITE;
/*!40000 ALTER TABLE `User` DISABLE KEYS */;
INSERT INTO `User` VALUES (1,'john_doe','password123',1),(2,'jane_smith','securepass456',2),(3,'chef_ravi','delicious789',2),(4,'employee_mike','workhard101',3),(5,'employee_susan','greatjob202',3),(6,'admin_anna','adminpass303',1),(7,'chef_kumar','tastyfood404',2),(8,'employee_johnny','service505',3),(9,'admin_sam','manager606',1),(10,'chef_alia','spicy707',2),(11,'vanshaj','dadhich',1),(12,'DadhichV','Vanshaj@123',3),(13,'InTimeTec','Itt@123',1);
/*!40000 ALTER TABLE `User` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `UserProfile`
--

DROP TABLE IF EXISTS `UserProfile`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `UserProfile` (
  `userId` bigint unsigned NOT NULL,
  `vegetarianPreference` int DEFAULT NULL,
  `spiceLevelOption` int DEFAULT NULL,
  `foodPreference` int DEFAULT NULL,
  `sweetToothPreference` int DEFAULT NULL,
  PRIMARY KEY (`userId`),
  CONSTRAINT `UserProfile_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `UserProfile`
--

LOCK TABLES `UserProfile` WRITE;
/*!40000 ALTER TABLE `UserProfile` DISABLE KEYS */;
INSERT INTO `UserProfile` VALUES (1,1,1,1,1),(2,2,1,1,1),(3,3,3,3,1),(4,1,1,1,1),(5,2,2,2,0),(6,3,3,3,1),(7,1,1,1,1),(8,2,2,2,0),(9,3,3,3,1),(10,1,1,1,1),(11,2,2,2,0),(12,3,3,3,1),(13,1,1,1,1);
/*!40000 ALTER TABLE `UserProfile` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `discardMenuItemDetailedFeedback`
--

DROP TABLE IF EXISTS `discardMenuItemDetailedFeedback`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `discardMenuItemDetailedFeedback` (
  `id` int NOT NULL AUTO_INCREMENT,
  `userId` bigint unsigned DEFAULT NULL,
  `menuItemId` bigint unsigned DEFAULT NULL,
  `whatYouLiked` varchar(255) DEFAULT NULL,
  `howWouldItTaste` varchar(255) DEFAULT NULL,
  `shareRecipe` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `userId` (`userId`),
  KEY `menuItemId` (`menuItemId`),
  CONSTRAINT `discardMenuItemDetailedFeedback_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE CASCADE,
  CONSTRAINT `discardMenuItemDetailedFeedback_ibfk_2` FOREIGN KEY (`menuItemId`) REFERENCES `MenuItem` (`menuItemId`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `discardMenuItemDetailedFeedback`
--

LOCK TABLES `discardMenuItemDetailedFeedback` WRITE;
/*!40000 ALTER TABLE `discardMenuItemDetailedFeedback` DISABLE KEYS */;
INSERT INTO `discardMenuItemDetailedFeedback` VALUES (3,2,21,'quantity ','ore spicy','dd mirchi'),(4,2,21,'quantity','ore spicy','dd salt'),(5,2,21,'fresh','ess salty','dd less salt'),(6,2,21,'fresh','more salty','add more salt'),(7,2,27,'taste','it was more salty','add less salt');
/*!40000 ALTER TABLE `discardMenuItemDetailedFeedback` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `todayMenu`
--

DROP TABLE IF EXISTS `todayMenu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `todayMenu` (
  `menuItemId` bigint unsigned NOT NULL,
  PRIMARY KEY (`menuItemId`),
  CONSTRAINT `todayMenu_ibfk_1` FOREIGN KEY (`menuItemId`) REFERENCES `MenuItem` (`menuItemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `todayMenu`
--

LOCK TABLES `todayMenu` WRITE;
/*!40000 ALTER TABLE `todayMenu` DISABLE KEYS */;
/*!40000 ALTER TABLE `todayMenu` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-08-20 10:17:09
