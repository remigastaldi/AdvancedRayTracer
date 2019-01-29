#pragma once

#include <QtCore/qglobal.h>

#if defined(ADVANCED_RAY_TRACER_LIBRARY)
#  define ADVANCED_RAY_TRACER_EXPORT Q_DECL_EXPORT
#else
#  define ADVANCED_RAY_TRACER_EXPORT Q_DECL_IMPORT
#endif
