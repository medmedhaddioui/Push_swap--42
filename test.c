int maxProfit(int* prices, int pricesSize) 
{
    int i;
    i = 0;
    int index_min = 0;
    int index_max = 0;;
    int min = 2147483647 ;
    int max = -2147483648;
    if (pricesSize == 2)
    {
        if (prices[0] < prices[1])
        {
        min = prices[0];
        max = prices[1];
        return max - min;
        }
        return 0;
    }
    while (i < pricesSize)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            index_min = i;
        }
        if (index_min >= index_max)
        {
            int j;
            j = i;
            int tmp;
            tmp = 0;
            max = prices[i];
            while (j < pricesSize)
            {
                if (prices[j] > tmp)
                {
                    tmp = prices[j];
                    index_max = j;
                }
                j++;
            }
            max = tmp;
        }
        i++;
    }
    if (index_min <= index_max)
      return 0;
    int result ;
    result = max - min;
    return result;
}