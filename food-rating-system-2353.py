"""
Leetcode #2353 Design a Food Rating System
https://leetcode.com/problems/design-a-food-rating-system
9 September 2025
Time Complexity: O(log n) for each changeRating and highestRated call
Space Complexity: O(n) for initialization storing all foods
"""

import heapq
from typing import List


class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_to_rating = dict()
        self.food_to_cuisine = dict()
        self.cuisine_foods = dict()

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_to_cuisine[food] = cuisine
            self.food_to_rating[food] = rating
            self.cuisine_foods.setdefault(cuisine, [])

            heapq.heappush(self.cuisine_foods[cuisine], (-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine = self.food_to_cuisine[food]
        self.food_to_rating[food] = newRating
        heapq.heappush(self.cuisine_foods[cuisine], (-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        heap = self.cuisine_foods[cuisine]
        while heap:
            rating, food = heap[0]
            if -rating == self.food_to_rating[food]:
                return food
            heapq.heappop(heap)


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
