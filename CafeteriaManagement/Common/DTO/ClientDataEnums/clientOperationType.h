#pragma once

enum Operation : int
{
   AddUser = 0,
   AddMenuItem = 1,
   DeleteMenuItem = 2,
   UpdateMenuItem = 3,
   ViewMenu = 4,
   RollOutMenuForNextDay = 5,
   GenerateReport = 6,
   PublishMenuForToday = 7,
   ViewNotification = 8,
   ProvideFeedback = 9,
   VoteItemFromTomorrowMenu = 10,
   Login = 11,
   GetRecommandationFromEngine = 12,
   GetTodaysMenu = 13,
   GetChefRollOutMenuForTomorrow = 14,
   GetDiscardMenuList = 15,
   RemoveMenuItemFromList = 16,
   ProvideDiscardMenuItemDetailedFeedback = 17,
   GetMenuItemIdForDetailFeedbackFromChef = 18
};
