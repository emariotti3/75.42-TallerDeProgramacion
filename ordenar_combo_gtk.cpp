#include <gtkmm.h>
#include <sstream>
#include <string.h>
#include <stack>
#define COMBO_SIZE 10

void ReverseCombo(Gtk::ComboBoxText *combo){
	std::stack<Glib::ustring> optns;
	Glib::ustring optn;
	while (combo->get_active_row_number() != -1){
		optn = combo->get_active_text();
		combo->remove_text(0);
		optns.push(optn);
		combo->set_active(0);
	}
	while (!optns.empty()){
		optn = optns.top();
		optns.pop();
		combo->append(optn);
	}
}

class Combo: public Gtk::ComboBoxText{
	private:
		int tam;
	public:
		Combo();
};

Combo::Combo():
tam(COMBO_SIZE){
	for (int i = 0; i < tam; i++){
		std::stringstream s;
		s << i;
		std::string string("OPTN " + s.str()); 
		append(string);
	}
	this->set_active(0);
}

class Window : public Gtk::Window{
	protected:
		Gtk::Box box;
		Combo combo;
		Gtk::Button btn;
	public:
		Window();
};

Window::Window():
box(Gtk::ORIENTATION_VERTICAL),
btn("REVERSE COMBO"){
	add(box);
	
	btn.signal_clicked().connect(sigc::bind(sigc::ptr_fun(&ReverseCombo), &combo));
	box.pack_start(combo);
	box.pack_start(btn);
	
	box.show();
	btn.show();
	combo.show();

}

int main(int argc, char *argv[]){
	Gtk::Main kit(argc, argv);
	Window window;
	Gtk::Main::run(window);
}

