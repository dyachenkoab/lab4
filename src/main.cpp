#include "mySpace.h"

int main()
{
    mySpace::printIP(int8_t { -1 });
    mySpace::printIP(int16_t { 0 });
    mySpace::printIP(int32_t { 2130706433 });
    mySpace::printIP(int64_t { 8875824491850138409 });
    mySpace::printIP(vector<int> { 100, 200, 300, 400 });
    mySpace::printIP(list<short> { 400, 300, 200, 100 });
    mySpace::printIP(string { "Hello world!" });

    return 0;
}
