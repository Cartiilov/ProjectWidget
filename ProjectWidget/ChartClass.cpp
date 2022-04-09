#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"
#include <math.h>

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
    cfg= std::move(c);
    x_step=200;
}

void ChartClass::Set_Range()
{
 double xmin=9999.9,xmax=-9999.9,ymin=9999.9,ymax=-9999.9;
 double x,y,step;
 int i;

 xmin=cfg->Get_x_start();
 xmax=cfg->Get_x_stop();

 step=(cfg->Get_x_stop()-cfg->Get_x_start())/(double)x_step;
 x=cfg->Get_x_start();

 for (i=0;i<=x_step;i++)
  {
   y=GetFunctionValue(x);
   if (y>ymax) ymax=y;
   if (y<ymin) ymin=y;
   x=x+step;
  }

 y_min=ymin;
 y_max=ymax;
 x_min=xmin;
 x_max=xmax;
}


double ChartClass::GetFunctionValue(double x)
{
 if (cfg->Get_F_type()==1) return x*x;
 if (cfg->Get_F_type()==2) return 0.5*exp(4*x-3*x*x);
 return x+sin(x*4.0);
}

void ChartClass::Draw(wxDC *dc, int w, int h)
{
 dc->SetBackground(wxBrush(RGB(255, 255, 255)));
 dc->Clear();
 dc->SetPen(wxPen(RGB(255, 0, 0)));
 dc->DrawRectangle(10, 10, w - 20, h - 20);
 dc->SetClippingRegion(wxRect(10, 10, w - 20, h - 20));
 //dc->DrawText("Tu trzeba narysowac wykres", wxPoint(20, 20));

 Matrix mMatrix;

 if (cfg->RotateScreenCenter())
     mMatrix = Rotate(w, h) * Move_Via_Axis()* Set_Scale(w, h);
 else
     mMatrix = Move_Via_Axis()* Rotate(w, h) * Set_Scale(w, h);




 dc->SetPen(wxPen(RGB(0, 0, 255)));

 line2d(mMatrix, cfg->Get_x_start(), 0, cfg->Get_x_stop(), 0, w, h, dc);
 line2d(mMatrix, 0, Get_Y_min(), 0, Get_Y_max(), w, h, dc);

 double x_jump = 0.8 + static_cast<int>((cfg->Get_x1() - cfg->Get_x0()) / 10);
 double y_jump = 0.8 + static_cast<int>((cfg->Get_y1() - cfg->Get_y0()) / 10);

 for (double x = x_min; x <= x_max; x += x_jump / 2)
 {
     line2d(mMatrix, x, -0.05, x, 0.05, w, h, dc);
     line2d(mMatrix, x, -0.05, x, 0.05, w, h, dc);
     RotateText(dc, mMatrix, wxString::Format(wxT("%2.1f"), x), x - 0.02, -0.05, w, h);
 }

 line2d(mMatrix, x_max, 0, x_max - 0.05, 0 + 0.05, w, h, dc);
 line2d(mMatrix, x_max, 0, x_max - 0.05, 0 - 0.05, w, h, dc);

 for (double y = y_min; y <= y_max; y += y_jump / 2)
 {
     line2d(mMatrix, -0.05, y, 0.05, y, w, h, dc);
     RotateText(dc, mMatrix, wxString::Format(wxT("%2.1f"), y), 0.075, y + 0.05, w, h);
 }

 line2d(mMatrix, 0, y_max, 0 + 0.05, y_max - 0.05, w, h, dc);
 line2d(mMatrix, 0, y_max, 0 - 0.05, y_max - 0.05, w, h, dc);

 double step = (cfg->Get_x1() - cfg->Get_x0()) / x_step;
 dc->SetPen(wxPen(RGB(0, 255, 0)));
 for (double x = (cfg->Get_x_start()); x < (cfg->Get_x_stop()); x += step) {
     line2d(mMatrix, x, GetFunctionValue(x), x + step, GetFunctionValue(x + step), w, h, dc);
 }
}


void ChartClass::line2d(Matrix t, double x1, double y1, double x2, double y2, int w, int h, wxDC* dc)
{
    Vector one, two;

    one.data[0] = x1;
    one.data[1] = y1;
    one.data[2] = 1;

    two.data[0] = x2;
    two.data[1] = y2;
    two.data[2] = 1;

    one = t * one;
    two = t * two;

    dc->DrawLine(static_cast<wxCoord>(one.GetX()), static_cast<wxCoord>(h - one.GetY()), static_cast<wxCoord>(two.GetX()), static_cast<wxCoord>(h - two.GetY()));

}

double ChartClass::Get_Y_min()
{
    Set_Range();
    return y_min;
}

double ChartClass::Get_Y_max()
{
    Set_Range();
    return y_max;
}

Matrix ChartClass::Set_Scale(int w, int h) {
    Matrix tMatrix;

    double Sx, Sy;

    Sx = (w - x_min)/ (cfg->Get_x1() - cfg->Get_x0());
    Sy = (h - y_min) / (cfg->Get_y1() - cfg->Get_y0());

    tMatrix.data[0][0] = Sx;
    tMatrix.data[0][2] = x_min - Sx * cfg->Get_x0();
    tMatrix.data[1][1] = Sy;
    tMatrix.data[1][2] = y_min - Sy * cfg->Get_x0();

    return tMatrix;

}

Matrix ChartClass::Rotate(int w, int h) {
    Matrix mMatrix;
    double cosinus = cos(cfg->Get_Alpha() * M_PI / 180);
    double sinus = sin(cfg->Get_Alpha() * M_PI / 180);
    mMatrix.data[0][0] = cosinus;
    mMatrix.data[0][1] = sinus;
    mMatrix.data[1][0] = -sinus;
    mMatrix.data[1][1] = cosinus;

    if (cfg->RotateScreenCenter())
    {
        mMatrix.data[0][2] = (w / 2.0) * (1 - cosinus) + (h / 2.0) * (-sinus);
        mMatrix.data[1][2] = (w / 2.0) * sinus + (h / 2.0) * (1 - cosinus);
    }
    else
    {
        Matrix tmp = Set_Scale(w, h);
        mMatrix.data[0][2] = tmp.data[0][2] * (1 - cosinus) + tmp.data[1][2] * (-sinus);
        mMatrix.data[1][2] = tmp.data[0][2] * sinus + tmp.data[1][2] * (1 - cosinus);
    }
    return mMatrix;


}

Matrix ChartClass::Move_Via_Axis()
{
    Matrix temp_object;

    temp_object.data[0][0] = temp_object.data[1][1] = 1;
    temp_object.data[0][2] = cfg->Get_dX();
    temp_object.data[1][2] = cfg->Get_dY();

    return temp_object;

}

void ChartClass::RotateText(wxDC* DC, Matrix trans_matrix, wxString str, double x, double y, int w, int h)
{
    Vector vector;
    vector.Set(x, y);
    vector = trans_matrix * vector;
    DC->DrawRotatedText(str, static_cast<wxCoord>(vector.GetX()), static_cast<wxCoord>(h - vector.GetY()), -cfg->Get_Alpha());
}