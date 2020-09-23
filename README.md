# Class "Date"
> Implementation of the class with multiple constructors and a destructor. Implementation of the specified list of overloaded operations for the class.

> **TAGS:** C++, OOP

The implemented class "Date" is designed to represent dates.

## The following constructors are defined in the class:
- default
- by year
- by year and month
- by full date
- copy constructor

## The date is registered by default as a static member of the class.

## Functions-modifiers for changing the date by an integer amount are implemented:
- change year
- change month
- change days

## The following operators are overloaded:
- "=" // Assignment
- "+=" (Date & d, int n) // add n days
- "-=" (Date & d, int n) // subtract n days
- "+" (Date & d, int n) // add n days
- "-" (Date & d, int n) // subtract n days
- increment / decrement
- ==,! =,>, < // comparison operators
- ">>", "<<" // (input/output using istream/ostream streams)
## Constant member functions to query the year, month, day are prescribed

## The developed Date class allows such use
```c
int main()

{

    Date date1, date2(1995), date3(1995, Date::mar), date4(1995, Date::may,5);
    date1 = date2 + date3;    // doesn't work!
    
    Date tdate1,tdate2;
    tdate1 += 2;
    tdate2++; tdate2++;                      
    if (tdate1 != tdate2) cout << "Something wrong\n";
    else cout << "As expected\n";
    
    cout << date1 << endl << date2 << endl << date3 << endl  << date4 << endl;
    
    Date today = Date(2018, Date::sep, 10);
    Date tomorrow = today + 1;
    
    Date never = 43 + today;  // doesn't work!

return 0;

}
```
