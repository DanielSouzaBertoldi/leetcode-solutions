```
The general ideia to tackle this challenge (after numerous attempts) was to just get all possible combinations of the list, filter duplicated combinations and then focus on the combinations that started with 0, 1 or 2.

If the sequence starts with 0 or 1, then we just need to check if the third value in the list (that is, the minutes first digit) is less than 6, then we make a quick check to verify that the sequence being valuated is greater than the currently stored hour. If yes, then we store the current sequence in our hour variable.

If the sequence starts with 2, then the only adittional verification is to check if the second value in the list is less than 5. If it also complies to the above rules, then the hour variable stores the current sequence.

Finally, if the sequence didn't change at all from its starting position ([0,0,0,0]), then that means that no other combination is a valid one, returning an empty string. Otherwise, return the greates hour found.
```
import itertools

class Solution:
  def largestTimeFromDigits(self, A: List[int]) -> str:
    if all(num == 0 for num in A):
      return "00:00"

    possibilities = list(itertools.permutations(A))
    possibilities = set(possibilities)

    hour = (0,0,0,0)
    for sequence in possibilities:
      if (sequence[0] == 0 or sequence[0] == 1) and sequence[2] < 6 and sequence > hour:
        hour = sequence
      elif sequence[0] == 2 and sequence[1] < 4 and sequence[2] < 6 and sequence > hour:
        hour = sequence

    if hour == (0,0,0,0):
      return ""
    return f"{hour[0]}{hour[1]}:{hour[2]}{hour[3]}"
