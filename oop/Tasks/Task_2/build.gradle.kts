import org.gradle.api.internal.plugins.MainClass

plugins {
    id("java")
    id("application")
}

application{
 mainClass.set("example.Main")
}
group = "org.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:6.0.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    testRuntimeOnly("org.junit.platform:junit-platform-launcher")
}

tasks.test {
    useJUnitPlatform()
}
tasks.jar{
    manifest {
        attributes["Main-Class"] = "org.example.Main"
    }
}
tasks.named<JavaExec>("run") {
    standardInput = System.`in`
}