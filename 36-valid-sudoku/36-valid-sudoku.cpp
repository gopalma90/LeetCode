class Solution {
public:

bool checkForSameRow(vector<int> temp)
{
    if ( temp.size() < 3 )
        return false;
	vector<int> vec;
	for (int i = 0; i <= temp.size() - 2; i++)
	{
		vec.push_back(temp[i]);
		i++;
	}
	sort ( vec.begin(), vec.end() );
        for ( int i =0; i< vec.size()-1 ; i++ )
			if (vec[i] == vec[i+1] )
				return true;
	return false;
}

bool checkForSameColumn(vector<int> temp)
{
	vector<int> vec;
	if ( temp.size() > 2 ){
		for (int i = 1; i <= temp.size() - 1; i++)
		{
			vec.push_back(temp[i]);
			i++;
		}
		sort ( vec.begin(), vec.end() );
		for ( int i =0; i< vec.size()-1 ; i++ )
			if (vec[i] == vec[i+1] )
				return true;
	}
	return false;
}

bool checkForSameSquare(vector<int> temp)
{
	int size = temp.size();
	vector<int> squarebool = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < size - 1; i++)
	{
		if (temp[i] <= 2)
		{
			if (temp[i + 1] <= 2)
			{
				if (squarebool[0])
					return true;
				squarebool[0] = 1;
			}
			else if (temp[i + 1] <= 5)
			{
				if (squarebool[1])
					return true;
				squarebool[1] = 1;
			}
			else if (temp[i + 1] <= 8)
			{
				if (squarebool[2])
					return true;
				squarebool[2] = 1;
			}
		}
		else if (temp[i] <= 5)
		{
			if (temp[i + 1] <= 2)
			{
				if (squarebool[3])
					return true;
				squarebool[3] = 1;
			}
			else if (temp[i + 1] <= 5)
			{
				if (squarebool[4])
					return true;
				squarebool[4] = 1;
			}
			else if (temp[i + 1] <= 8)
			{
				if (squarebool[5])
					return true;
				squarebool[5] = 1;
			}
		}
		else if (temp[i] <= 8)
		{
			if (temp[i + 1] <= 2)
			{
				if (squarebool[6])
					return true;
				squarebool[6] = 1;
			}
			else if (temp[i + 1] <= 5)
			{
				if (squarebool[7])
					return true;
				squarebool[7] = 1;
			}
			else if (temp[i + 1] <= 8)
			{
				if (squarebool[8])
					return true;
				squarebool[8] = 1;
			}
		}

		i++;
	}

	return false;
}
    
bool isValidSudoku(vector<vector<char> > &board)
{
	map<char, vector<int>> pos;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				auto it = pos.find(board[i][j]);
				if (it != pos.end())
				{
					vector<int> temp = it->second;
					temp.push_back(i);
					temp.push_back(j);
					pos[board[i][j]] = temp;
				}
				else
				{
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					pos[board[i][j]] = temp;
				}
			}
		}
	}
	
	for (auto it = pos.begin(); it != pos.end(); it++)
	{
		vector<int> temp = it->second;
        
		if (checkForSameRow(it->second))
		{
			return false;
		}
		if (checkForSameColumn(it->second))
		{
			return false;
		}
        
		if (checkForSameSquare(it->second))
		{
			return false;
		}
	}

	return true;
}
};