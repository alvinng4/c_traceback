import {MetaRecord} from "nextra";

const DOCS_ITEMS: MetaRecord = {
    index: '',
    navigation: '',
    tips: '',
}


export default {
    index: {
        type: 'page',
        theme: {
            layout: 'full',
            toc: false,
            timestamp: false,
        }
    },
    docs: {
        type: 'page',
        title: 'Documentation',
        items: DOCS_ITEMS
    },
    article: {
        type: 'page',
        theme: {
            toc: false,
            typesetting: 'article',
        }
    },
    contact: {
        type: 'page',
        theme: {
            layout: 'full',
            toc: false,
            timestamp: false,
        }
    },
}