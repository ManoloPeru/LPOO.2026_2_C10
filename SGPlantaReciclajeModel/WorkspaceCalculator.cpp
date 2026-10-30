#include "WorkspaceCalculator.h"

using namespace SGPlantaReciclajeModel;

List<PointF>^ WorkspaceCalculator::CalcularEspiral(double a, double b) {
	// Validación de parámetros: 'a' debe ser >= 0 y 'b' > 0
    if (a < 0 || b <= 0)
        throw gcnew ArgumentException("El radio inicial 'a' debe ser >= 0 y la expansion 'b' debe ser > 0.");

    List<PointF>^ puntos = gcnew List<PointF>();
    const double paso = 0.05;
    double limite = 6.0 * Math::PI; // 3 vueltas completas
	// Calcular los puntos de la espiral de Arquímedes
    for (double theta = 0.0; theta < limite; theta += paso) {
        double r = a + b * theta;
        double x_mm = r * Math::Cos(theta);
        double y_mm = r * Math::Sin(theta);
        puntos->Add(PointF((float)x_mm, (float)y_mm));
    }

    // Agregar el punto exacto en el límite (6*PI) para cerrar la trayectoria
    double r_final = a + b * limite;
    puntos->Add(PointF((float)(r_final * Math::Cos(limite)), (float)(r_final * Math::Sin(limite))));

    return puntos;
}