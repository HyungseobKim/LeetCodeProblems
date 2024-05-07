class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int numZeroes = 0; // For cases that 0 is the best result.

        // Add a dummy 0 for easier iteration.
        if (nums[nums.size() - 1] != 0)
        {
            nums.push_back(0);
            --numZeroes;
        }

        const int size = nums.size();
        int best = nums[0];

        int numNegatives = 0;
        int begin = 0;

        for (int i = 0; i < size; ++i)
        {
            const int num = nums[i];

            if (num < 0)
            {
                ++numNegatives;
            }
            else if (num == 0)
            {
                if (numNegatives == 1)
                {
                    // If the negative number is the only element of nums, it is already stored in the best.
                    if (begin + 1 < i)
                    {
                        int product = 1;

                        // When the negative number is the first element.
                        if (nums[begin] < 0)
                        {
                            for (int j = begin + 1; j < i; ++j)
                            {
                                product *= nums[j];
                            }
                        }// When the negative number is the last element.
                        else if (nums[i - 1] < 0)
                        {
                            for (int j = begin; j < i - 1; ++j)
                            {
                                product *= nums[j];
                            }
                        }
                        else // We need to compute the products for two different parts.
                        {
                            int j = begin;

                            while (nums[j] > 0)
                            {
                                product *= nums[j];
                                ++j;
                            }

                            ++j;
                            int product2 = 1;

                            while (j < i)
                            {
                                product2 *= nums[j];
                                ++j;
                            }

                            product = std::max(product, product2);
                        }

                        best = std::max(best, product);
                    }
                }// If the number of negatives are odd, we need to compute the products for three different parts.
                else if (numNegatives % 2)
                {
                    // The product before the first negative number.
                    int productLeft = 1;
                    int j = begin;

                    while (nums[j] > 0)
                    {
                        productLeft *= nums[j];
                        ++j;
                    }

                    const int firstNegative = nums[j];
                    ++j;
                    --numNegatives;

                    // The product between the first negative and last negative number.
                    int productMid = 1; // will include the last negative.
                    
                    while (numNegatives)
                    {
                        if (nums[j] < 0)
                        {
                            --numNegatives;
                        }

                        productMid *= nums[j];
                        ++j;
                    }

                    const int lastNegative = nums[j-1];
                    
                    // The product after the last negative number.
                    int productRight = 1;
                    while (j < i)
                    {
                        productRight *= nums[j];
                        ++j;
                    }

                    // [begin, last negative) vs (first negative, i)
                    best = std::max(best, std::max(productMid * productRight, (productMid / lastNegative) * firstNegative * productLeft));
                }
                else
                {
                    int product = nums[begin];

                    for (int j = begin + 1; j < i; ++j)
                    {
                        product *= nums[j];
                    }

                    best = std::max(best, product);
                }

                ++numZeroes;

                begin = i + 1;
                numNegatives = 0;
            }
        }

        if (best < 0 && numZeroes > 0)
        {
            return 0;
        }

        return best;
    }
};