#pragma once

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "connection.hpp"

class NamedChanel final : public Connection<const char*>
{
    NamedChanel(const char *pathname, bool create);
    virtual bool Read(void *buf, size_t count) override;
    virtual bool Write(void *buf, size_t count) override;
    virtual ~NamedChanel() override;
private:
    int fd;
};