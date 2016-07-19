#include <gtkmm.h>
#include <sstream>
#include <string.h>

class Editor : public Gtk::Entry{
	public:
		Editor();
		void format_editor_content();
		void capitalize_all();
};

Editor::Editor(){
	this->set_text("hello world? how are you doing?");
}

void Editor::capitalize_all(){
	Glib::ustring text = this->get_text();
	this->set_text(text.uppercase());
}

void Editor::format_editor_content(){
	std::string text = this->get_text();
	std::stringstream iterator;
	iterator << text;
	std::string word = "";
	std::string result = "";
	
	while (iterator >> word){
		word[0] = std::toupper(word[0]);
		result += word + " ";
	}
	this->set_text(result);
}

class Window : public Gtk::Window{
	protected:
		Gtk::Box box;
		Gtk::Button btn;
		Gtk::Button btn2;
		Editor editor;
	public:
		Window();
};

Window::Window():
box(Gtk::ORIENTATION_VERTICAL),
btn("CAPITALIZE"),
btn2("CAPITALIZE ALL")
{
	set_title("Editor");
	set_default_size(640, 400);
	
	btn.signal_clicked().connect(sigc::mem_fun(editor, &Editor::format_editor_content));
	btn2.signal_clicked().connect(sigc::mem_fun(editor, &Editor::capitalize_all));
	
	add(box);
	
	box.pack_start(editor);
	box.pack_start(btn);
	box.pack_start(btn2);
	
	btn.show();
	btn2.show();
	editor.show();
	
	box.show();
}

int main(int argc, char *argv[]){
	Gtk::Main kit(argc, argv);
	Window window;
	Gtk::Main::run(window);
	return 0;
}
