#include <gtkmm.h>

class Triangulo: public Gtk::DrawingArea{
	public:
		bool on_draw(const Cairo::RefPtr<Cairo::Context> &ctx);
};

bool Triangulo::on_draw(const Cairo::RefPtr<Cairo::Context> &ctx){
	Glib::RefPtr< Gdk::Window > window = get_window();
	if (window){
		Gtk::Allocation alloc = get_allocation();
		int width = alloc.get_height();
		int height = alloc.get_width();
		
		ctx->save();
		ctx->move_to(0, height);
		ctx->set_source_rgb(1.0,0.0,0.0);
		ctx->line_to(width, 0);
		ctx->line_to(width, height);
		ctx->close_path();
		ctx->fill();
		ctx->stroke();
		ctx->restore();
	}
	return true;
}

int main(int argc, char *argv[]){
	Gtk::Main kit(argc, argv);
	Gtk::Window window;
	window.set_default_size(400, 400);
	Triangulo triangulo;
	window.add(triangulo);
	window.show_all();
	Gtk::Main::run(window);
	return 0;
}
