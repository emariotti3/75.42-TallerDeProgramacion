
/*
 * 10) Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un rombo como el que se muestra en la siguiente figura:
 * Es un rombito así:
 *  
 * |/\|
 * |\/|
 */

#include <gtkmm.h>

class Rombo : public Gtk::DrawingArea {
	public:
	private:
		bool on_draw(const Cairo::RefPtr< Cairo::Context >& ctx){
			Glib::RefPtr< Gdk::Window > window = get_window();
			if (window) {
				Gtk::Allocation alloc = get_allocation();
				const int height = alloc.get_height();
				const int width = alloc.get_width();
				//ELIPSE:
				int xc, yc;
				xc = width / 2;
				yc = height / 2;
				
				ctx->save();
				
				double ew, eh;
				ew = 3.0 * width / 4.0;
				eh = height / 3.0;
				ctx->save();
				ctx->translate(xc, yc);
				ctx->scale(ew / 2.0, eh / 2.0);
				ctx->arc(0.0, 0.0, 1.0, 0.0, 2*M_PI);
				ctx->fill_preserve();
				ctx->restore();
				ctx->stroke();
				//FIN ELIPSE
				
				//ROMBO
				/*ctx->scale(width, height); //escalado para que ocupe siempre toda la pantalla. Notar que es ancho y después alto.
				
				ctx->move_to(0.5, 1.0); // muevo hacia el punto inicial, que arbitrariamente elegí que fuera el de abajo
				ctx->line_to(0.0, 0.5); // línea hacia el punto de la izquierda
				ctx->line_to(0.5, 0.0); // línea hacia el punto de arriba
				ctx->line_to(1.0, 0.5); // línea hacia el punto de la derecha
				ctx->close_path(); // cierro el camino
				ctx->fill(); // relleno todo de negro, el color por defecto*/
				//FIN ROMBO
			}
			return true;	
		}
};

int main(int argc, char* argv[]) {
	Gtk::Main kit(argc, argv);	
	Rombo rombo;
	Gtk::Window v;
	v.add(rombo);
	v.show_all();
	Gtk::Main::run(v);
	return 0;
}	
