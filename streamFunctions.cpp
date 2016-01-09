

std::string trimline(string& str)
{
    std::size_t first = str.find_first_not_of(' ');
    std::size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}


std::vector<string> splitline(string input, char delimiter)
  {
     vector<string> output;
     size_t start = 0;
     size_t end = 0;
 
     while (start != string::npos && end != string::npos)
     {
        start = input.find_first_not_of(delimiter, end);
 
        if (start != string::npos)
        {
           end = input.find_first_of(delimiter, start);
 
           if (end != string::npos)
           {
              output.push_back(input.substr(start, end - start));
           }
           else
           {
              output.push_back(input.substr(start));
           }
        }
     }
 
     return output;
 
  }

