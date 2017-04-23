
#include "Terminal.h"

Terminal::Terminal() {
    set_type(1);
}

Terminal::~Terminal() {
    
}


void Terminal::set_name(string data){
    name = data;
    set_tab_first(data);
}
