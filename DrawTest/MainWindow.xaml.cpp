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

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));

        // draw line using mx_line
        mx_line().X1(0);
        mx_line().Y1(0);
        mx_line().X2(100);
        mx_line().Y2(100);
        mx_line().Stroke(Microsoft::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Red()));
        mx_line().StrokeThickness(5);
        mx_line().StrokeStartLineCap(Microsoft::UI::Xaml::Media::PenLineCap::Round);
        mx_line().StrokeEndLineCap(Microsoft::UI::Xaml::Media::PenLineCap::Round);
        mx_line().StrokeLineJoin(Microsoft::UI::Xaml::Media::PenLineJoin::Round);
        mx_line().StrokeMiterLimit(1);
        MainWindow::mx_canvas().Children().Append(mx_line());
        MainWindow::mx_canvas().Children().Clear();
               
    }
}
