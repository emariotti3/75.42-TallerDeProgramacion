/*Escriba el trozo de código necesario para pasar el contenido
de un edit a mayúsculas.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtkmm.h>


void capitalize_edit(Gtk::Entry *entry){
    Glib::ustring text = entry->get_text();
    entry->set_text(text.uppercase());
}

int main(int argc, char *argv[]){
    Gtk::Main kit(argc, argv);
    Gtk::Entry entry;
    entry.set_text("Esto es un texto de prueba.");
    Gtk::Button btn("CAPITALIZE");
    Gtk::Box box(Gtk::ORIENTATION_VERTICAL);

    btn.signal_clicked().connect(sigc::bind(sigc::ptr_fun(&capitalize_edit), &entry));

    box.pack_start(entry);
    box.pack_start(btn);

    Gtk::Window window;
    window.set_default_size(400,400);
    window.set_title("CAPITALIZE");
    window.add(box);
    window.show_all();

    Gtk::Main::run(window);
    return 0;
}
