#include <iostream>
#include <vector>

using namespace std;

int
main (int argc, char const *argv[])
{

  vector < int >nums = { 1, 2, 3, 4 };
  vector < int >res (nums.size ());

  int helper = 1;

  res[0] = 1;

  for (int i = 0; i < nums.size () - 1; i++)
    {
      res[i + 1] = helper * nums[i];
      helper *= nums[i];
    }

  helper = 1;

  for (int i = nums.size()-1; i > 0; i--)
    {
      res[i - 1] *= helper * nums[i];
      helper *= nums[i];
    }

  for (int i = 0; i < nums.size (); i++)
    {

      cout << res[i] << " ";
    }


  return 0;
}

