#ifndef __STOUT_FS_HPP__
#define __STOUT_FS_HPP__

#include <unistd.h> // For symlink.

#include <sys/statvfs.h>

#include <string>

#include "error.hpp"
#include "nothing.hpp"
#include "try.hpp"

// TODO(bmahler): Migrate the appropriate 'os' namespace funtions here.
namespace fs {

// Returns the total available disk size in bytes.
inline Try<uint64_t> available(const std::string& path = "/")
{
  struct statvfs buf;
  if (::statvfs(path.c_str(), &buf) < 0) {
    return ErrnoError();
  }
  return buf.f_bavail * buf.f_frsize;
}


// Returns relative disk usage of the file system mounted at the given path.
inline Try<double> usage(const std::string& fs = "/")
{
  struct statvfs buf;
  if (statvfs(fs.c_str(), &buf) < 0) {
    return ErrnoError("Error invoking statvfs of '" + fs + "'");
  }
  return (double) (buf.f_blocks - buf.f_bfree) / buf.f_blocks;
}


inline Try<Nothing> symlink(
    const std::string& original,
    const std::string& link)
{
  if (::symlink(original.c_str(), link.c_str()) < 0) {
    return ErrnoError();
  }
  return Nothing();
}

} // namespace fs {

#endif // __STOUT_FS_HPP__
