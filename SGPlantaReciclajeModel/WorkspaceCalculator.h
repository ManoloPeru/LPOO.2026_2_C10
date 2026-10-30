#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace SGPlantaReciclajeModel {
    public ref class WorkspaceCalculator {
    public:
        // Calcula la espiral de Arquímedes de 0 a 6*PI
        List<PointF>^ CalcularEspiral(double a, double b);
    };
}