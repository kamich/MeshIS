#ifndef MESHIS_APPSTARTPOINT_H
#define MESHIS_APPSTARTPOINT_H
#include <functional>
#include <vector>
using std::vector;
using std::function;

class AppStartPoint
{
public:
    static void render();
    static void reshape(int width, int height);

    void setFunctionsToRender(vector<function<void()>> const &);

    static enum MENU_TYPE
    {
        SAVE_STATE,
        LOAD_STATE
    };

private:
    static void cleanWindow();
    static vector<function<void()>> renderFunctions;
};

#endif //MESHIS_APPSTARTPOINT_H
