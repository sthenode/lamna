///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: rectangle.hpp
///
/// Author: $author$
///   Date: 7/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_RECTANGLE_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_RECTANGLE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {

template <typename TNumber>
class pointt {
public:
    TNumber x, y;
    pointt(TNumber _x, TNumber _y) : x(_x), y(_y) { }
    pointt(const pointt& copy) : x(copy.x), y(copy.y) { }
    pointt() : x(0), y(0) { }
    virtual ~pointt() { }
};
typedef pointt<int> point_t;

template <typename TNumber>
class sizet {
public:
    TNumber width, height;
    sizet(TNumber _width, TNumber _height) : width(_width), height(_height) { }
    sizet(const sizet& copy) : width(copy.width), height(copy.h) { }
    sizet() : width(0), height(0) { }
    virtual ~sizet() { }
};
typedef sizet<int> size_t;

template
<typename TNumber,
 typename TPoint = surface::pointt<TNumber>,
 typename TSize = surface::sizet<TNumber> >

class rectanglet {
public:
    TPoint origin;
    TSize size;

    rectanglet(const TSize& fromSize, const TSize& toSize): origin(0,0), size(0,0) {
        resize(fromSize, toSize);
    }
    rectanglet(int nx, int ny, int nw, int nh): origin(nx, ny), size(nw, nh) { }
    rectanglet(): origin(0,0), size(0,0) { }

    rectanglet& resize(const TSize& fromSize, const TSize& toSize) {
        return resize(*this, fromSize, toSize);
    }
    rectanglet& normalize(const TSize& fromSize, const TSize& toSize) {
        return normalize(*this, fromSize, toSize);
    }
    rectanglet& normalize(const TSize& toSize) {
        return normalize(*this, toSize);
    }

    static rectanglet& resize
    (rectanglet& rect, const TSize& fromSize, const TSize& toSize) {
        if (toSize.height < toSize.width) {
            if ((rect.size.width = (toSize.height * fromSize.width) / fromSize.height) > toSize.width) {
                rect.size.height = (toSize.width * fromSize.height) / fromSize.width;
                rect.size.width = toSize.width;
            } else {
                rect.size.height = toSize.height;
            }
        } else {
            if ((rect.size.height = (toSize.width * fromSize.height) / fromSize.width) > toSize.height) {
                rect.size.width = (toSize.height * fromSize.width) / fromSize.height;
                rect.size.height = toSize.height;
            } else {
                rect.size.width = toSize.width;
            }
        }
        rect.origin.x = (toSize.width - rect.size.width) / 2;
        rect.origin.y = (toSize.height - rect.size.height) / 2;
        return rect;
    }
    static rectanglet& normalize
    (rectanglet& rect, const TSize& fromSize, const TSize& toSize) {
        resize(rect, fromSize, toSize);
        normalize(rect, toSize);
        return rect;
    }
    static rectanglet& normalize
    (rectanglet& rect, const TSize& toSize) {
        rect.origin.x /= toSize.width; rect.origin.y /= toSize.height;
        rect.size.width /= toSize.width; rect.size.height /= toSize.height;
        return rect;
    }
};
typedef rectanglet<int, surface::point_t, surface::size_t> rectangle_t;

} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_RECTANGLE_HPP 
