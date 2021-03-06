#include <skia/core/SkGraphics.h>
#include <skia/core/SkCanvas.h>
#include <skia/effects/SkGradientShader.h>
#include <skia/effects/SkDiscretePathEffect.h>

SkPath star() {
    const SkScalar R = 60.0f, C = 128.0f;
    SkPath path;
    path.moveTo(C + R, C);
    for (int i = 1; i < 15; ++i) {
        SkScalar a = 0.44879895f * i;
        SkScalar r = R + R * (i % 2);
        path.lineTo(C + r * cos(a), C + r * sin(a));
    }
    return path;
}

int main(SkCanvas* canvas) {
    SkPaint paint;
    paint.setPathEffect(SkDiscretePathEffect::Make(10.0f, 4.0f));
    SkPoint points[2] = {SkPoint::Make(0.0f, 0.0f), SkPoint::Make(256.0f, 256.0f)};
    SkColor colors[2] = {SkColorSetRGB(66, 133, 244), SkColorSetRGB(15, 157, 88)};
    paint.setShader(SkGradientShader::MakeLinear(points, colors, NULL, 2, SkTileMode::kClamp, 0, NULL));
    paint.setAntiAlias(true);
    canvas->clear(SK_ColorWHITE);
    SkPath path(star());
    canvas->drawPath(path, paint);
}
