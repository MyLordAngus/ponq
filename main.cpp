#include <QtGui>

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(-200, -200, 400, 400);

	QGraphicsView view(&scene);
	view.show();

	return app.exec();
}
