#include <QGraphicsItem>
#include <QRectF>

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class Ball : public QGraphicsItem
{
public:
	Ball();

	QRectF boundingRect() const;
	void paint(QPainter* painter,
			const QStyleOptionGraphicsItem* option,
			QWidget* widget = 0);
	void advance(int phase);

private:
	qreal angle;
};
