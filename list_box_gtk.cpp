#include <gtkmm.h>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char *argv[]){
	Gtk::Main kit(argc, argv);
	Gtk::Window window;
	
	window.set_default_size(640, 480);
	window.set_title("Gtk List Box");
	window.set_position(Gtk::WIN_POS_CENTER);
	//window.maximize(); //creo que es para hacerla full-screen.
	Gtk::ListBox list;
	Gtk::ListBoxRow row[20];
	
	for (int i = 0; i < 20; i++){
		std::stringstream converter;
		converter << "lista" << i;
		row[i].add_label(converter.str());
		list.append(row[i]);
	}
	list.show();
	
	window.add(list);
	window.show_all();
	
	Gtk::Main::run(window);
	return 0;
}

		//std::stringstream converter;
		//converter << i;
		//GtkWidget * w = (GtkWidget *) (GTK_TYPE_LIST_BOX_ROW,"selectable",FALSE,"activatable",FALSE,NULL);
