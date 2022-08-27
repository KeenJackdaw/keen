package com.keenjackdaw.keen.core.framework;


import com.keenjackdaw.keen.core.app.Application;
import com.keenjackdaw.keen.core.launcher.Launcher;

public abstract class BaseLauncher implements Launcher {
    private Application application;

    @Override
    public void launch(Application application) {
        // Start launcher lifecycle
        init();

        // Context
        application.setLauncher(this);
        setApplication(application);

        // Start application lifecycle
        application.init();
        application.start();
        application.render();
        application.stop();

        // End launcher lifecycle
        stop();
    }

    @Override
    public void init() {

    }

    @Override
    public void stop() {

    }

    @Override
    public Application getApplication() {
        return application;
    }

    @Override
    public void setApplication(Application application) {
        this.application = application;
    }
}
