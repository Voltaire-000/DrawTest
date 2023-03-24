// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.Shapes.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Shapes;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.



namespace winrt::DrawTest::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void DrawLine()
    {
        Microsoft::UI::Xaml::Controls::Canvas mx_canvas;
        Microsoft::UI::Xaml::Shapes::Line mx_line;
        mx_line.X1(0);
        mx_line.Y1(0);
        mx_line.X2(0); // set to 0 for now
        mx_line.Y2(0); // set to 0 for now
        mx_line.StrokeThickness(5);
        mx_line.Stroke(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::Colors::Aqua()));
        mx_canvas.Children().Append(mx_line);

        // add canvas to the visual tree
        Microsoft::UI::Xaml::Window window = Microsoft::UI::Xaml::Window::Current();
        window.Content(mx_canvas);
        window.Activate();

        // wait for the layout pass to complete
        mx_canvas.UpdateLayout();

        // set the line's end points based on the canvas size
        mx_line.X2(mx_canvas.ActualWidth());
        mx_line.Y2(mx_canvas.ActualHeight());
    }


    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));

        DrawLine();

        //Microsoft::UI::Xaml::Controls::Canvas mx_canvas;
        //Microsoft::UI::Xaml::Shapes::Line mx_line;

        //mx_line.X1(0);
        //mx_line.Y1(0);
        //mx_line.X2(mx_canvas.ActualWidth());
        //mx_line.Y2(mx_canvas.ActualHeight());
        //mx_line.StrokeThickness(5);
        //mx_line.Stroke(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::Colors::Aqua()));
        //mx_canvas.Children().Append(mx_line);
              
    }

}
