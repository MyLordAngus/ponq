#include <QtGui>

#include "Ball.h"

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(-200, -200, 400, 400);

	Ball* ball = new Ball;
	scene.addItem(ball);

	QGraphicsView view(&scene);
	view.setRenderHints(QPainter::Antialiasing |
			QPainter::SmoothPixmapTransform);
	view.show();

	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	timer.start(1000 / 33);

	return app.exec();
}
