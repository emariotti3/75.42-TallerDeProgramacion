#include <stdio.h>
#include <stdlib.h>
#include <gtkmm.h>

void close_app(){
    Gtk::Main::quit();
}

int main(int argc, char *argv[]){
    Gtk::Main kit(argc,argv);
    Gtk::Button btn("Close");

    btn.signal_clicked().connect(sigc::ptr_fun(&close_app));

    Gtk::Window window;
    window.add(btn);
    window.set_default_size(200,200);
    window.set_title("GTK Button");
    window.show_all();

    Gtk::Main::run(window);
    return 0;
}
