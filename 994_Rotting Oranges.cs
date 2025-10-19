public class Solution
{
    public int OrangesRotting(int[][] grid)
    {
        int height = grid.Length;
        int fresh = 0;
        Queue<(int y, int x)> rotten_oranges = new Queue<(int, int)>();
        for (int y = 0; y < height; ++y)
        {
            int[] row = grid[y];
            int width = row.Length;

            for (int x = 0; x < width; ++x)
            {
                int value = row[x];

                if (value == 1)
                {
                    ++fresh;
                }
                else if (value == 2)
                {
                    rotten_oranges.Enqueue((y, x));
                }
            }
        }

        if (fresh == 0)
        {
            return 0;
        }

        int count = rotten_oranges.Count;
        int nextCount = 0;
        int time = -1;

        while (rotten_oranges.Count > 0)
        {
            var rotten_orange = rotten_oranges.Dequeue();

            for (int i = 0; i < 4; ++i)
            {
                (int y, int x) neighbor = (rotten_orange.y + adjacent_y[i], rotten_orange.x + adjacent_x[i]);

                if (neighbor.y >= 0 && neighbor.y < height && neighbor.x >= 0 && neighbor.x < grid[neighbor.y].Length)
                {
                    int value = grid[neighbor.y][neighbor.x];

                    if (value == 1)
                    {
                        --fresh;
                        grid[neighbor.y][neighbor.x] = 2;
                        rotten_oranges.Enqueue(neighbor);
                        ++nextCount;
                    }
                }
            }

            --count;
            if (count == 0)
            {
                ++time;
                count = nextCount;
                nextCount = 0;
            }
        }

        if (fresh == 0)
        {
            return time;
        }

        return -1;
    }

    private readonly int[] adjacent_x = { 1, -1, 0, 0 };
    private readonly int[] adjacent_y = { 0, 0, 1, -1 };
}