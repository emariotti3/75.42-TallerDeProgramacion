#include <stdio.h>
#include <stdlib.h>
#include <gtkmm.h>

int main(int argc, char *argv[]){
    //Inicializamos el framework
    Gtk::Main kit(argc, argv);

    Gtk::CheckButton button("Checkbox button");

    Gtk::Window window;
    window.set_default_size(400,400);
    window.add(button);
    window.show_all();

    //Iniciamos el loop de eventos
    Gtk::Main::run(window);
    return 0;
}
