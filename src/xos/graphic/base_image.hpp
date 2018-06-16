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
///   File: base_image.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_BASE_IMAGE_HPP
#define _XOS_GRAPHIC_BASE_IMAGE_HPP

#include "xos/graphic/image_interface.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: base_imaget
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TBase = base,
 class TExtends = TBase>

class _EXPORT_CLASS base_imaget: public TExtends {
public:
    typedef TExtends extends;

    typedef TImageInterface tImageInterface;
    typedef TBase tBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    base_imaget(tImageInterface& image): m_image(image) {
    }
    virtual ~base_imaget() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = image.plot(x,y);
        return error;
    }
    virtual eError fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image.fill(x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError plot(tOffset x, tOffset y) {
        eError error = m_image.plot(x,y);
        return error;
    }
    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = m_image.fill(x,y, w,h);
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageInterface& m_image;
};
typedef base_imaget<> base_image;

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_BASE_IMAGE_HPP 
