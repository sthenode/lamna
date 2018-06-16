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
///   File: image.hpp
///
/// Author: $author$
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_HPP

#include "xos/graphic/surface/image_interface.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: imaget
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TImageInterface = image_interface,
 class TImage = image,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TImageInterface, class TExtends = TImage>

class _EXPORT_CLASS imaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TContextInterface tContextInterface;
    typedef TImageInterface tImageInterface;
    typedef TImage tImage;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    imaget(tContextInterface& context, tImageInterface* image)
    : extends(image), m_context(context) {
    }
    imaget(tContextInterface& context): m_context(context) {
    }
    virtual ~imaget() {
    }

    virtual tContextInterface& context_interface() const {
        return (tContextInterface&)m_context;
    }

protected:
    tContextInterface& m_context;
};
typedef imaget<> image;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_HPP 
