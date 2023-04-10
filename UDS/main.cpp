#include "Application/Application.h"
#include "Core/Log.h"

int main(){
    Application app;
    app.Init();

    if(!app.Run()){
        LOG_ERROR("Error occurred while trying to run Application");        
    }

    app.Destroy();
    return 0;
}
