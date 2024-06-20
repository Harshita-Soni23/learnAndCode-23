CREATE DATABASE RecommendationEngine;

USE RecommendationEngine;

CREATE TABLE IF NOT EXISTS MenuItem(
    menuItemId BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    menuItemName VARCHAR(255) NOT NULL,
    menuItemType ENUM('Breakfast', 'Lunch', 'Dinner') NOT NULL,
    Availability BOOLEAN NOT NULL,
    Price DECIMAL(10, 2) NOT NULL
);

CREATE TABLE IF NOT EXISTS Notification(
    NotificationId BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    NotificationTitle VARCHAR(255) NOT NULL,
    message VARCHAR(255) NOT NULL,
    timestamp DATETIME NOT NULL
);

CREATE TABLE IF NOT EXISTS User(
    Employeeid BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    userName VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    Role ENUM('Admin', 'Chef', 'Employee') NOT NULL,
    lastNotificationId BIGINT UNSIGNED,
    FOREIGN KEY (lastNotificationId) REFERENCES Notification(NotificationId)
);

CREATE TABLE IF NOT EXISTS Feedback(
    feedbackId BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    userId BIGINT UNSIGNED NOT NULL,
    MenuItemId BIGINT UNSIGNED NOT NULL,
    Rating INT NOT NULL,
    comment VARCHAR(255) NOT NULL,
    timestamp DATE NOT NULL,
    FOREIGN KEY (userId) REFERENCES User(Employeeid),
    FOREIGN KEY (MenuItemId) REFERENCES MenuItem(menuItemId)
);


CREATE TABLE IF NOT EXISTS RecommandationSelection(
    id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    menuItemId BIGINT UNSIGNED NOT NULL,
    selectionCount BIGINT NOT NULL,
    sentimentScore BIGINT NOT NULL,
    FOREIGN KEY (menuItemId) REFERENCES MenuItem(menuItemId)
);

INSERT INTO MenuItem (menuItemId, menuItemName, menuItemType, Availability, Price) VALUES
(1, 'Masala Dosa', 'Breakfast', true, 6.99),
(2, 'Aloo Paratha', 'Breakfast', true, 5.49),
(3, 'Paneer Butter Masala', 'Lunch', true, 8.99),
(4, 'Chole Bhature', 'Lunch', true, 7.49),
(5, 'Chicken Biryani', 'Lunch', true, 10.99),
(6, 'Rogan Josh', 'Dinner', true, 12.99),
(7, 'Butter Chicken', 'Dinner', true, 11.49),
(8, 'Palak Paneer', 'Dinner', true, 9.99),
(9, 'Idli Sambar', 'Breakfast', true, 4.99),
(10, 'Lamb Vindaloo', 'Dinner', true, 13.99);

INSERT INTO Notification (NotificationId, NotificationTitle, message, timestamp) VALUES
(1, 'Welcome', 'Welcome to our food service!', '2024-06-01 09:00:00'),
(2, 'New Menu Item', 'We have added new dishes to our menu!', '2024-06-02 10:30:00'),
(3, 'Discount Offer', 'Get 20% off on all orders today!', '2024-06-03 11:00:00'),
(4, 'Holiday Hours', 'We will be closed on Independence Day.', '2024-06-04 12:00:00'),
(5, 'Feedback Request', 'Please provide feedback for your recent order.', '2024-06-05 13:45:00'),
(6, 'Recipe of the Day', 'Try our special Chicken Biryani recipe today!', '2024-06-06 08:15:00'),
(7, 'App Update', 'New features added to the mobile app!', '2024-06-07 14:30:00'),
(8, 'Service Interruption', 'We will be undergoing maintenance from 2 AM to 4 AM.', '2024-06-08 03:00:00'),
(9, 'Event Invitation', 'Join us for a cooking workshop this weekend.', '2024-06-09 16:00:00'),
(10, 'Loyalty Program', 'Join our loyalty program and earn rewards!', '2024-06-10 17:30:00');


INSERT INTO User (Employeeid, userName, password, Role, lastNotificationId) VALUES
(1, 'john_doe', 'password123', 'Admin', 1),
(2, 'jane_smith', 'securepass456', 'Chef', 2),
(3, 'chef_ravi', 'delicious789', 'Chef', 3),
(4, 'employee_mike', 'workhard101', 'Employee', 4),
(5, 'employee_susan', 'greatjob202', 'Employee', 5),
(6, 'admin_anna', 'adminpass303', 'Admin', 6),
(7, 'chef_kumar', 'tastyfood404', 'Chef', 7),
(8, 'employee_johnny', 'service505', 'Employee', 8),
(9, 'admin_sam', 'manager606', 'Admin', 9),
(10, 'chef_alia', 'spicy707', 'Chef', 10);


INSERT INTO Feedback (feedbackId, userId, MenuItemId, Rating, comment, timestamp) VALUES
(1, 1, 1, 5, 'Delicious and perfect!', '2024-06-01'),
(2, 2, 3, 4, 'Very tasty, but a bit too spicy.', '2024-06-02'),
(3, 3, 5, 3, 'It was okay, nothing special.', '2024-06-03'),
(4, 4, 2, 5, 'Absolutely loved it!', '2024-06-04'),
(5, 5, 4, 4, 'Good but could use more seasoning.', '2024-06-05'),
(6, 6, 6, 5, 'Amazing dish, highly recommend!', '2024-06-06'),
(7, 7, 8, 4, 'Pretty good, will order again.', '2024-06-07'),
(8, 8, 7, 5, 'Fantastic flavor, well cooked.', '2024-06-08'),
(9, 9, 9, 3, 'Average, expected more.', '2024-06-09'),
(10, 10, 10, 5, 'Perfectly sweet and delightful!', '2024-06-10');


INSERT INTO RecommandationSelection (id, menuItemId, selectionCount, sentimentScore) VALUES
(1, 1, 150, 4.5),
(2, 2, 120, 4.2),
(3, 3, 200, 4.8),
(4, 4, 175, 4.1),
(5, 5, 110, 3.9),
(6, 6, 140, 4.3),
(7, 7, 160, 4.7),
(8, 8, 130, 4.0),
(9, 9, 155, 4.4),
(10, 10, 180, 4.6);
