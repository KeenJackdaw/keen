package com.keenjackdaw.keen.core.framework;


import com.keenjackdaw.keen.core.app.Application;
import com.keenjackdaw.keen.core.launcher.Launcher;

import java.io.OutputStream;

public abstract class BaseApplication implements Application {
    private Launcher launcher;

    @Override
    public void init() {

    }

    @Override
    public void start() {

    }

    @Override
    public void render() {
        System.out.println("Hello Keen!!");
    }

    @Override
    public void stop() {

    }

    @Override
    public void help(OutputStream outputStream) {

    }

    @Override
    public Launcher getLauncher() {
        return launcher;
    }

    @Override
    public void setLauncher(Launcher launcher) {
        this.launcher = launcher;
    }
}
