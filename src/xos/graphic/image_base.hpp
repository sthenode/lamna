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
///   File: image_base.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_BASE_HPP
#define _XOS_GRAPHIC_IMAGE_BASE_HPP

#include "xos/graphic/image_base_interface.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: image_baset
///////////////////////////////////////////////////////////////////////
template
<class TImageBaseInterface = image_base_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TBase = base,
 class TImplements = TImageBaseInterface, class TExtends = TBase>

class _EXPORT_CLASS image_baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TImageBaseInterface tImageBaseInterface;
    typedef TBase tBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    image_baset(tImageBaseInterface& image): image_(image) {
    }
    virtual ~image_baset() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError plot
    (tImageBaseInterface& pixel, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        error = pixel.plot(image_, x,y);
        return error;
    }
    virtual eError fill
    (tImageBaseInterface& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        error = pixel.fill(image_, x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageBaseInterface& image_;
};
typedef image_baset<> image_base;

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_BASE_HPP 
