class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        std::map<int, std::vector<int>> table;

        for (auto& event : events)
            table[event[0]].push_back(event[1]);

        for (auto& event : table)
            std::sort((event.second).begin(), (event.second).end());

        // Allocate array for events currently on going.
        int size = events.size();
        int* remainingEvents = new int[size];
        int* tempArray = new int[size];

        // Attend first event and copy others.
        const auto end = table.end();
        auto itr = table.begin();
        size = itr->second.size();

        for (int i = 1; i < size; ++i)
            remainingEvents[i - 1] = itr->second[i];

        int attend = 1;
        int day = itr->first + 1;
        ++itr;

        int eventsNum = size - 1;
        int eventIndex = 0;

        while (itr != end)
        {
            const int nextStartDay = itr->first;

            // Ignore all events that already ended.
            while (eventIndex < eventsNum && remainingEvents[eventIndex] < day)
                ++eventIndex;

            // Attend events already started.
            while (day < nextStartDay)
            {
                // Ignore all events that already ended.
                while (eventIndex < eventsNum && remainingEvents[eventIndex] < day)
                    ++eventIndex;

                // No events remain.
                if (eventIndex == eventsNum)
                {
                    day = nextStartDay;
                    break;
                }

                // Attend an event.
                if (remainingEvents[eventIndex] >= day)
                {
                    ++attend;
                    ++day;
                    ++eventIndex;
                }
            }

            // Merge existing events and new events.
            int index1 = eventIndex;
            int index2 = 0;

            auto& nextEvents = itr->second;
            size = nextEvents.size();

            int index = 0;
            while (index1 < eventsNum && index2 < size)
            {
                if (remainingEvents[index1] < nextEvents[index2])
                {
                    tempArray[index] = remainingEvents[index1];
                    ++index1;
                }
                else
                {
                    tempArray[index] = nextEvents[index2];
                    ++index2;
                }

                ++index;
            }

            while (index1 < eventsNum)
            {
                tempArray[index] = remainingEvents[index1];
                ++index1;
                ++index;
            }

            while (index2 < size)
            {
                tempArray[index] = nextEvents[index2];
                ++index2;
                ++index;
            }

            // Change container.
            eventsNum = index;
            std::swap(remainingEvents, tempArray);

            // Attend first event of merged list.
            ++day;
            ++attend;
            eventIndex = 1;

            // Move to next day.
            ++itr;
        }

        // Attend events that started lastly, but not ended yet.
        while (eventIndex < eventsNum)
        {
            if (remainingEvents[eventIndex] >= day)
            {
                ++attend;
                ++day;
            }

            ++eventIndex;
        }

        return attend;
    }
};