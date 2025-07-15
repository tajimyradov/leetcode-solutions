class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        has_vowel = False
        has_consonant = False
        vowels = "aeiouAEIOU"

        for char in word:
           
            if not char.isalnum():
                return False

           
            if char.isalpha(): 
                if char in vowels:
                    has_vowel = True
                else:
                    has_consonant = True

        return has_vowel and has_consonant


solution = Solution()

print(f"'234Adas': {solution.isValid('234Adas')}")   
print(f"'a3b': {solution.isValid('a3b')}")      
print(f"'abc': {solution.isValid('abc')}")      
print(f"'b': {solution.isValid('b')}")         
print(f"'234': {solution.isValid('234')}")        
print(f"'aeiou': {solution.isValid('aeiou')}")    
print(f"'bcdf': {solution.isValid('bcdf')}")      
print(f"'Hello!': {solution.isValid('Hello!')}")  
print(f"'HelloWorld': {solution.isValid('HelloWorld')}")