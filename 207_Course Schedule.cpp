class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> table(numCourses, std::vector<int>());
        std::vector<int> unresolved_courses(numCourses, 0);

        // For each course, make a list for courses that this course affect.
        // = i is the prerequisite course of the courses in table[i].
        for (const std::vector<int>& prerequisite : prerequisites)
        {
            table[prerequisite[1]].push_back(prerequisite[0]);
            ++unresolved_courses[prerequisite[0]];
        }

        // Push all courses that don't have unresolved prerequisites.
        std::queue<int> possible_courses;
        for (int i = 0; i < numCourses; ++i)
        {
            if (unresolved_courses[i] == 0)
            {
                possible_courses.push(i);
            }
        }

        int scheduled = 0;

        // For each courses can be taken, remove this course from the courses that this course affects.
        while (possible_courses.size())
        {
            const int possible_course = possible_courses.front();
            possible_courses.pop();
            ++scheduled;

            for (const int course : table[possible_course])
            {
                --unresolved_courses[course];

                if (unresolved_courses[course] == 0)
                {
                    possible_courses.push(course);
                }
            }
        }

        return scheduled == numCourses;
    }
};